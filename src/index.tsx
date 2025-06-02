import CycuridSdk from './NativeCycuridSdk';
import { CycurIdType, CycuridConfig } from './CycuridTypes';

export function initCycurid(
  type: CycurIdType,
  options: CycuridConfig
): Promise<string> {
  return new Promise((resolve, reject) => {
    if (
      options.apiKey == null ||
      options.secretKey == null ||
      options.userId == null
    ) {
      reject(
        new Error(
          'Missing required configuration: apiKey, secretKey, or userId is null or undefined.'
        )
      );
    } else {
      CycuridSdk.initCycurid(type, options.toJson())
        .then((result: string) => {
          resolve(result);
        })
        .catch((error: any) => {
          reject(error);
        });
    }
  });
}

export { CycurIdType, CycuridConfig };
