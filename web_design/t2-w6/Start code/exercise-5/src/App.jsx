import Card from "./components/Card.jsx";
import { TEAM_MEMBERS } from "./data.js";

function App() {
  return (
    <main>
      <h1>Meet Our Team</h1>
      <ul className="cards">
        {TEAM_MEMBERS.map((member) => (
          <Card key={member.id} member={member} />
        ))}
      </ul>
    </main>
  );
}

export default App;
