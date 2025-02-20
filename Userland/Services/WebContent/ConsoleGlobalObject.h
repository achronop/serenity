/*
 * Copyright (c) 2021-2022, Sam Atkins <atkinssj@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Forward.h>
#include <LibJS/Runtime/Completion.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibWeb/HTML/Window.h>

namespace WebContent {

class ConsoleGlobalObject final : public JS::GlobalObject {
    JS_OBJECT(ConsoleGlobalObject, JS::GlobalObject);

public:
    ConsoleGlobalObject(JS::Realm&, Web::HTML::Window&);
    virtual void initialize(JS::Realm&) override;
    virtual ~ConsoleGlobalObject() override = default;

    virtual JS::ThrowCompletionOr<Object*> internal_get_prototype_of() const override;
    virtual JS::ThrowCompletionOr<bool> internal_set_prototype_of(Object* prototype) override;
    virtual JS::ThrowCompletionOr<bool> internal_is_extensible() const override;
    virtual JS::ThrowCompletionOr<bool> internal_prevent_extensions() override;
    virtual JS::ThrowCompletionOr<Optional<JS::PropertyDescriptor>> internal_get_own_property(JS::PropertyKey const& name) const override;
    virtual JS::ThrowCompletionOr<bool> internal_define_own_property(JS::PropertyKey const& name, JS::PropertyDescriptor const& descriptor) override;
    virtual JS::ThrowCompletionOr<bool> internal_has_property(JS::PropertyKey const& name) const override;
    virtual JS::ThrowCompletionOr<JS::Value> internal_get(JS::PropertyKey const&, JS::Value) const override;
    virtual JS::ThrowCompletionOr<bool> internal_set(JS::PropertyKey const&, JS::Value value, JS::Value receiver) override;
    virtual JS::ThrowCompletionOr<bool> internal_delete(JS::PropertyKey const& name) override;
    virtual JS::ThrowCompletionOr<JS::MarkedVector<JS::Value>> internal_own_property_keys() const override;

    void set_most_recent_result(JS::Value result) { m_most_recent_result = move(result); }

private:
    virtual void visit_edges(Visitor&) override;

    // $0, the DOM node currently selected in the inspector
    JS_DECLARE_NATIVE_FUNCTION($0_getter);
    // $_, the value of the most recent expression entered into the console
    JS_DECLARE_NATIVE_FUNCTION($__getter);
    // $(selector, element), equivalent to `(element || document).querySelector(selector)`
    JS_DECLARE_NATIVE_FUNCTION($_function);
    // $$(selector, element), equivalent to `(element || document).querySelectorAll(selector)`
    JS_DECLARE_NATIVE_FUNCTION($$_function);

    Web::HTML::Window* m_window_object;
    JS::Value m_most_recent_result { JS::js_undefined() };
};

}
