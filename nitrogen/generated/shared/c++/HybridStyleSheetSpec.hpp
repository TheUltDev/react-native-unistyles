///
/// HybridStyleSheetSpec.hpp
/// Wed Aug 21 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif





namespace margelo::nitro::unistyles {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `StyleSheet`
   * Inherit this class to create instances of `HybridStyleSheetSpec` in C++.
   * @example
   * ```cpp
   * class HybridStyleSheet: public HybridStyleSheetSpec {
   *   // ...
   * };
   * ```
   */
  class HybridStyleSheetSpec: public HybridObject {
    public:
      // Constructor
      explicit HybridStyleSheetSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridStyleSheetSpec() { }

    public:
      // Properties
      virtual double getHairlineWidth() = 0;

    public:
      // Methods
      

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "StyleSheet";
  };

} // namespace margelo::nitro::unistyles
