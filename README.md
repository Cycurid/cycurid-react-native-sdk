# react-native-cycurid-sdk

Cycurid liveness verification

## Installation

```sh
npm install react-native-cycurid-sdk
```

## Usage

### Refer to documentation for more details:
https://docs.cycurid.com/


A Basic Example:
```js
export default function App() {
  const [livenessResult, setLivenessResult] = useState<string | null>(null);

  const handleButtonPress = async (type: CycurIdType) => {

    const config = new CycuridConfig(
      'API_KEY',
      'SECRET_KEY',
      'test_user_react_native_01'
    );

    // CycurIdType can be either CycurIdType.isHuman or CycurIdType.onboarding. See documentation for more details.
    try {
      const result = await initCycurid(type, config);
      setLivenessResult(result);
    } catch (error) {
      console.error('Error:', error);
    }
  };

  return (
    <View style={styles.container}>
      <View style={styles.buttonContainer}>
        <Button
          title="Is Human"
          color="skyblue"
          onPress={() => handleButtonPress(CycurIdType.isHuman)}
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

```

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
