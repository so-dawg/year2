import React, { useState } from "react";

function App() {
  const DOLLAR_TO_EURO_RATIO = 0.92;
  const DOLLAR_TO_DONG_RATIO = 24560;

  const [valueDollars, setValueDollars] = useState(15);

  function dollarToEuro(valueInDollars) {
    return valueInDollars * DOLLAR_TO_EURO_RATIO;
  }

  function dollarToDong(valueInDollars) {
    return valueInDollars * DOLLAR_TO_DONG_RATIO;
  }

  const valueInEuro = dollarToEuro(valueDollars);
  const valueInDong = dollarToDong(valueDollars);

  return (
    <main>
      <h1>Currency Converter</h1>

      <p>
        <label htmlFor="dollars">Current value in dollars:</label>
        <input
          id="dollars"
          type="number"
          value={valueDollars}
          onChange={(e) => setValueDollars(parseFloat(e.target.value) || 0)}
          min="0"
          step="0.01"
        />

        <label htmlFor="dong">Value in Dong:</label>
        <input
          id="dong"
          type="text"
          value={valueInDong.toLocaleString('vi-VN')}
          readOnly
        />

        <label htmlFor="euro">Value in Euro:</label>
        <input
          id="euro"
          type="text"
          value={valueInEuro.toFixed(2)}
          readOnly
        />
      </p>

    </main>
  );
}

export default App;
