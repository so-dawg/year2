// DOMS ELEMENTS  ---------------------------------------------------------
const dom_quiz = document.querySelector("#quiz");
const dom_question = document.querySelector("#question");
const dom_choiceA = document.querySelector("#A");
const dom_choiceB = document.querySelector("#B");
const dom_choiceC = document.querySelector("#C");
const dom_choiceD = document.querySelector("#D");
const dom_score = document.querySelector("#score");
const dom_start = document.querySelector("#start");

dom_start.addEventListener("click", onStart);

// Add event listeners to answer buttons
dom_choiceA.addEventListener("click", () => onPlayerSubmit("A"));
dom_choiceB.addEventListener("click", () => onPlayerSubmit("B"));
dom_choiceC.addEventListener("click", () => onPlayerSubmit("C"));
dom_choiceD.addEventListener("click", () => onPlayerSubmit("D"));

// DATA  ---------------------------------------------------------
let questions = [
  {
    title: "What does HTML stand for?",
    choiceA: "Hi Thierry More Laught",
    choiceB: "How To move Left",
    choiceC: "Ho Theary Missed the Laundry !",
    choiceD: "Hypertext Markup Language",
    correct: "D",
  },
  {
    title: "What does CSS stand for?",
    choiceA: "Cisco and Super Start",
    choiceB: "Ci So Sa",
    choiceC: "Cascading Style Sheets ",
    choiceD: "I don't know !",
    correct: "C",
  },
  {
    title: "What does JS stand for?",
    choiceA: "Junior stars",
    choiceB: "Justing Star",
    choiceC: "Javascript",
    choiceD: "RonanScript",
    correct: "C",
  },
];
let runningQuestionIndex = 0;
let score = 0;

// FUNCTIONS ---------------------------------------------------------

function hide(element) {
  element.style.display = 'none';
}

function show(element) {
  element.style.display = 'block';
}

function onStart() {
  score = 0;
  runningQuestionIndex = 0;

  hide(dom_start);
  show(dom_quiz);

  renderQuestion();
}

function renderQuestion() {
  const q = questions[runningQuestionIndex];

  dom_question.textContent = q.title;
  dom_choiceA.textContent = q.choiceA;
  dom_choiceB.textContent = q.choiceB;
  dom_choiceC.textContent = q.choiceC;
  dom_choiceD.textContent = q.choiceD;
}

function onPlayerSubmit(answer) {
  // Check if the selected answer is correct
  if (answer === questions[runningQuestionIndex].correct) {
    score++;
  }

  runningQuestionIndex++;

  if (runningQuestionIndex < questions.length) {
    renderQuestion();
  } else {
    renderScore();
  }
}

function renderScore() {
  const scorePercent = Math.round((score / questions.length) * 100);

  dom_score.textContent = scorePercent;
  hide(dom_quiz);
  show(dom_score);

}

// FUNCTIONS ---------------------------------------------------------
show(dom_start);
hide(dom_quiz);
