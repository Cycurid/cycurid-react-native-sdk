export enum CycurIdType {
  isHuman = 'isHuman',
  onboarding = 'onboarding',
  verification = 'verification',
  identification = 'identification',
  dataExtraction = 'dataExtraction',
}

export class CycuridConfig {
  apiKey: string;
  secretKey: string;
  userId: string;

  constructor(apiKey: string, secretKey: string, userId: string) {
    this.apiKey = apiKey;
    this.secretKey = secretKey;
    this.userId = userId;
  }

  toJson(): string {
    return JSON.stringify({
      apiKey: this.apiKey,
      secretKey: this.secretKey,
      userId: this.userId,
    });
  }
}
