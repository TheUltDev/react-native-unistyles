package com.unistyles

import com.facebook.react.bridge.ReactApplicationContext

class Platform(reactApplicationContext: ReactApplicationContext) {
    private val config: UnistylesConfig = UnistylesConfig(reactApplicationContext)

    fun hasNewConfig(): Boolean {
        return this.config.hasNewConfig()
    }

    fun getConfig(): Config {
        return this.config.get()
    }
}
