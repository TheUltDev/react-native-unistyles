#pragma once

#include <jsi/jsi.h>
#include <jsi/JSIDynamic.h>
#include <folly/dynamic.h>
#include "Unistyle.h"
#include "Dimensions.hpp"
#include "Constants.h"
#include "Helpers.h"
#include "MediaQueries.h"
#include "HybridUnistylesRuntime.h"
#include "StyleSheet.h"

namespace margelo::nitro::unistyles::parser {

using namespace facebook;
using namespace margelo::nitro::unistyles::core;
    
using Variants = std::vector<std::pair<std::string, std::string>>;
 
struct Parser {
    Parser(std::shared_ptr<HybridUnistylesRuntime> unistylesRuntime): _unistylesRuntime{unistylesRuntime} {}
    
    void buildUnistyles(jsi::Runtime& rt, std::shared_ptr<StyleSheet> styleSheet);
    void parseUnistyles(jsi::Runtime& rt, std::shared_ptr<StyleSheet> styleSheet);
private:
    jsi::Object unwrapStyleSheet(jsi::Runtime& rt, std::shared_ptr<StyleSheet> styleSheet);
    jsi::Object parseFirstLevel(jsi::Runtime& rt, Unistyle::Shared unistyle, Variants& variants);
    jsi::Value parseSecondLevel(jsi::Runtime& rt, jsi::Value& nestedObject);
    jsi::Function createDynamicFunctionProxy(jsi::Runtime& rt, Unistyle::Shared unistyle, Variants& variants);
    std::vector<folly::dynamic> parseDynamicFunctionArguments(jsi::Runtime& rt, size_t count, const jsi::Value* arguments);
    std::vector<UnistyleDependency> parseDependencies(jsi::Runtime &rt, jsi::Object&& dependencies);
    jsi::Value parseTransforms(jsi::Runtime& rt, jsi::Object& obj);
    jsi::Value getValueFromBreakpoints(jsi::Runtime& rt, jsi::Object& obj);
    jsi::Object parseVariants(jsi::Runtime& rt, jsi::Object& obj, Variants& variants);
    jsi::Value getStylesForVariant(jsi::Runtime& rt, jsi::Object&& groupValue, std::optional<std::string> selectedVariant);
    jsi::Object parseCompoundVariants(jsi::Runtime& rt, jsi::Object& obj, Variants& variants);
    bool shouldApplyCompoundVariants(jsi::Runtime& rt, const Variants& variants, jsi::Object& compoundVariant);
    
    std::shared_ptr<HybridUnistylesRuntime> _unistylesRuntime;
};

}
