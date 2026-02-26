import Header from "./components/Header";
import Scores from "./components/Scores";
import { ENGLISH_RESULTS, HTML_RESULTS, JAVA_RESULTS, PYTHON_RESULTS } from "./data.js";

function App() {
  return (
    <>
      <Header />
      <main className="scores-container">
        <div className="scores">
          <Scores courseName="HTML" courseResults={HTML_RESULTS} />
        </div>

        <div className="scores">
          <Scores courseName="PYTHON" courseResults={PYTHON_RESULTS} />
        </div>
        <div className="scores">
          <Scores courseName="JAVA" courseResults={JAVA_RESULTS} />
        </div>
        <div className="scores">
          <Scores courseName="ENGLISH" courseResults={ENGLISH_RESULTS} />
        </div>
      </main>
    </>
  );
}

export default App;
