#pragma once

#include <jsi/jsi.h>
#include "Unistyle.h"
#include "Helpers.h"
#include "Constants.h"

namespace margelo::nitro::unistyles::core {

struct UnistyleWrapper: public jsi::NativeState {
    explicit UnistyleWrapper(Unistyle::Shared unistyle)
        : unistyle(std::move(unistyle)) {}

    ~UnistyleWrapper() override;

    Unistyle::Shared unistyle;
};

inline static Unistyle::Shared unistyleFromValue(jsi::Runtime& rt, const jsi::Value& value) {
    if (value.isNull()) {
        return nullptr;
    }

    return value.getObject(rt).getNativeState<UnistyleWrapper>(rt)->unistyle;
}

inline static jsi::Value valueFromUnistyle(jsi::Runtime& rt, Unistyle::Shared unistyle) {
    auto wrappedUnistyle = std::make_shared<UnistyleWrapper>(unistyle);

    if (unistyle->type == UnistyleType::Object) {
        jsi::Object obj = jsi::Object(rt);

        obj.setNativeState(rt, std::move(wrappedUnistyle));
        helpers::defineHiddenProperty(rt, obj, helpers::UNISTYLES_ID.c_str(), unistyle->styleKey);

        helpers::mergeJSIObjects(rt, obj, unistyle->parsedStyle.value());

        return obj;
    }

    auto unistyleFn = std::dynamic_pointer_cast<UnistyleDynamicFunction>(unistyle);
    auto hostFn = jsi::Value(rt, unistyleFn->proxiedFunction.value()).asObject(rt).asFunction(rt);

    hostFn.setNativeState(rt, std::move(wrappedUnistyle));
    helpers::defineHiddenProperty(rt, hostFn, helpers::UNISTYLES_ID.c_str(), unistyleFn->styleKey);

    return std::move(hostFn);
}

}
