import React, { useState } from "react";

function App() {
  const [inputValueA, setInputValueA] = useState("");
  const [inputValueB, setInputValueB] = useState("");
  const [result, setResult] = useState("");
  const [error, setError] = useState(false);

  function sumNum() {
    const numA = parseFloat(inputValueA);
    const numB = parseFloat(inputValueB);
    if (isNaN(numA) || isNaN(numB)) {
      setError(true);
      setResult("");
    } else {
      setResult(numA + numB);
      setError(false);
    }
  }

  function getDisplayValue() {
    if (error) {
      return "pls put numbers!";
    }
    return result;
  }

  return (
    <main>
      <h1>Calculator</h1>

      <label>A =</label>
      <input
        value={inputValueA}
        onChange={(e) => setInputValueA(e.target.value)}
      />

      <label>B =</label>
      <input
        value={inputValueB}
        onChange={(e) => setInputValueB(e.target.value)}
      />

      <label>A + B =</label>

      <input
        disabled
        value={getDisplayValue()}
        className={error ? "error" : ""}
      />
      <button onClick={sumNum}>Compute</button>
    </main>
  );
}

export default App;
