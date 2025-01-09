import CycuridSdk from './NativeCycuridSdk';
import { CycurIdType, CycuridConfig } from './CycuridTypes';

export function initCycurid(
  type: CycurIdType,
  options: CycuridConfig
): Promise<string> {
  return new Promise((resolve, reject) => {
    CycuridSdk.initCycurid(type, options.toJson())
      .then((result: string) => {
        resolve(result);
      })
      .catch((error: any) => {
        reject(error);
      });
  });
}

export { CycurIdType, CycuridConfig };
