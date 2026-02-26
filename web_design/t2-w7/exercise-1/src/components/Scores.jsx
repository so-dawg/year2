
export default function Scores({ courseName, courseResults }) {
  return (
    <>
      <section className="score">
        <h2>{courseName}</h2>
        {courseResults.map((student, index) => (

          <table>
            <thead>
              <tr>
                <th>First name</th>
                <th>Last name</th>
                <th>Score</th>
              </tr>
            </thead>

            <tbody key={index}>
              <tr >
                <td>{student.firstName}</td>
                <td>{student.lastName}</td>
                <td className={student.score < 50 ? "warning" : ""}>{student.score}</td>
              </tr>

            </tbody>
          </table>

        ))}
      </section>
    </>
  );
}
