export default function Card({ member }) {
  return (
    <li className="card-item">
      <div className="card-image">
        <img src={member.image.src} alt={member.image.alt} />
      </div>
      <div className="card-content">
        <h3>{member.name}</h3>
        <p className="role">{member.role}</p>
        <p className="location">📍 {member.location}</p>
        <div className="hobbies">
          <strong>Hobbies:</strong>
          <ul>
            {member.hobbies.map((hobby, index) => (
              <li key={index}>{hobby}</li>
            ))}
          </ul>
        </div>
      </div>
    </li>
  );
}
