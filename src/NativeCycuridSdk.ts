import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  initCycurid(type: string, options: string): Promise<string>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('CycuridSdk');
