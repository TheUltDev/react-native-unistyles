import { create } from './create'
import { UnistylesRuntime } from './runtime'
import { UnistylesState } from './state'
import { deepMergeObjects } from './utils'

export const StyleSheet = {
    configure: UnistylesState.init,
    create,
    absoluteFill: {
        position: 'absolute',
        left: 0,
        top: 0,
        right: 0,
        bottom: 0,
    },
    compose: (a: object, b: object) => deepMergeObjects(a, b),
    flatten: (...styles: Array<object>) => deepMergeObjects(...styles),
    hairlineWidth: 1
}

export { UnistylesRuntime } from './runtime'
export * from './mock'

export const getSSRUnistyles = () => UnistylesRuntime.getSSRUnistyles()
