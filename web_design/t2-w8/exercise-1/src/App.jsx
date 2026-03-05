import React, { useState } from "react";

function App() {
  const [isRain, setIsRain] = useState(false);

  function onSunClick() {
    setIsRain(false);
  }

  function onRainClick() {
    setIsRain(true);
  }

  function getTitle() {
    if (isRain) {
      return "Rain Time!";
    } else {
      return "Sun Time!";
    }
  }

  function getBackgroundColor() {
    if (isRain) {
      return "rainy";
    } else {
      return "sunny";
    }
  }

  return (
    <main className={getBackgroundColor()}>
      <h1>{getTitle()}</h1>
      <button onClick={onSunClick}>Sunny Time</button>
      <button onClick={onRainClick}>Rain Time</button>
    </main>
  );
}

export default App;
