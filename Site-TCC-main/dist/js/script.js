const menu = document.querySelector('.menu');
const NavMenu = document.querySelector('.nav-menu');

menu.addEventListener('click', () => {
    menu.classList.toggle('ativo');
    NavMenu.classList.toggle('ativo');
})

const links = document.querySelectorAll('.nav-item a');

links.forEach(link => {
  link.addEventListener('click', () => {
    document.querySelector('.menu').classList.remove('ativo');
    document.querySelector('.nav-menu').classList.remove('ativo');
  });
});

const label = document.querySelector('.theme');
const input = document.querySelector('.theme__toggle');
label.addEventListener('click', (event) => {
  if (event.target !== input) {
    event.preventDefault();
  }
});

const darkModeBtn = document.getElementById('theme');
const content = document.getElementById('content');

darkModeBtn.addEventListener('click', () => {
  document.body.classList.toggle('dark-mode');
});

