import React, { useState } from "react";

export default function StuffForm({ setStuffs }) {
  const [name, setName] = useState("");
  const [price, setPrice] = useState(0);

  function addItem(e) {
    e.preventDefault();
    setStuffs((prev) => [...prev, { name, price }]);
    setName("");
    setPrice(0);
  }

  return (
    <form className="stuff-form">
      <p>Stuff name</p>
      <input
        type="search"
        placeholder="Banana"
        value={name}
        onChange={(e) => {
          setName(String(e.target.value));
        }}
      />

      <p>Stuff price</p>
      <input
        type="search"
        placeholder="15"
        value={price}
        onChange={(e) => {
          setPrice(Number(e.target.value));
        }}
      />

      <button onClick={addItem}>Add Stuff</button>
    </form>
  );
}
