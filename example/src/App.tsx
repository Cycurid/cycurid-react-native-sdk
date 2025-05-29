import { useState } from 'react';
import { Text, View, StyleSheet, Button, Alert } from 'react-native';
import {
  initCycurid,
  CycurIdType,
  CycuridConfig,
} from 'react-native-cycurid-sdk';

export default function App() {
  const [livenessResult, setLivenessResult] = useState<string | null>(null);

  const handleButtonPress = async (type: CycurIdType) => {
    console.log(`Starting process for: ${type}`);
    const config = new CycuridConfig(
      'It04Ip0M5o2rPeQN9yheVHcmsFq79zdA',
      'Ueymke3TDVL8TED7Ec5qIzPXSVrr5c4gl_ANQrz2p4NSo5dI7X5j6I6b',
      'ekam_test_01'
    );

    try {
      const result = await initCycurid(type, config);
      console.log('InitCycurid Result:', result);
      Alert.alert('Process Started', result);
      setLivenessResult(result);
    } catch (error) {
      console.error('Error:', error);
      Alert.alert('Error', 'Failed to start process');
    }
  };

  return (
    <View style={styles.container}>
      <View style={styles.buttonContainer}>
        <Button
          title="Is Human"
          color="skyblue"
          onPress={() => handleButtonPress(CycurIdType.verification)}
        />
        <View style={styles.spacer} />
        <Button
          title="Onboarding"
          color="orange"
          onPress={() => handleButtonPress(CycurIdType.onboarding)}
        />
      </View>
      {livenessResult && (
        <Text style={styles.resultText}>Liveness Result: {livenessResult}</Text>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  buttonContainer: {
    flexDirection: 'column',
    alignItems: 'center',
    marginBottom: 20,
  },
  spacer: {
    height: 20,
  },
  resultText: {
    fontSize: 20,
    fontWeight: 'bold',
    marginVertical: 10,
  },
});
