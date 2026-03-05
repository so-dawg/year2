import React, { useState } from "react";
function App() {
  /* You will need to use a boolean state to keep the value of the text entered */
  const [inputValue, setInputValue] = useState("");

  /* Yo-u will need a function to handle a key pressed on the first input and update the state*/

  function convertToUpper() {
    return inputValue.toUpperCase();
  }

  return (
    <main>
      <h1>Upper Case Converter</h1>

      <label>Enter any text !</label>
      <input
        value={inputValue}
        onChange={(e) => setInputValue(e.target.value)}
        placeholder="Type something!"
      />

      <p>
        <label>Here is the text in upper case</label>

        {/* This input will need to display the text entered in lower case */}
        <input disabled placeholder={convertToUpper()} />
      </p>
    </main>
  );
}

export default App;
