import pnLogo from "../assets/pn-logo.png";
export default function Header() {
  return (
    <>
      <header id="header">
        <img src={pnLogo} alt="PN Logo" />
        <h1>Students results for (fake batch name)</h1>
      </header>
    </>
  );
}
