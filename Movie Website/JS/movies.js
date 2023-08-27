var movies;
const imgUrl = "https://image.tmdb.org/t/p/w500";

function search(searchValue) {
  let container = document.getElementById("container");
  container.innerHTML = "";

  if (searchValue === "") {
    getMovies();
    return;
  }

  movies.forEach((Movie) => {
    var MovieName = Movie.title;

    if (MovieName.toLowerCase().startsWith(searchValue.toLowerCase())) {
      const { id, poster_path, title } = Movie;

      let newMovie = document.createElement("div");
      newMovie.classList.add("Movie");

      newMovie.innerHTML = `
        <a href="./movieDetails.html?id=${id}">
          <img src="${imgUrl + poster_path}">
          <span>${title}</span>
        </a>`;

      container.appendChild(newMovie);
    }
  });
}

function getMovies() {
  const apiKey = "api_key=9813ce01a72ca1bd2ae25f091898b1c7";
  const url = "https://api.themoviedb.org/3";
  const path = "/discover/movie?sort_by=popularity.desc&";
  const apiUrl = url + path + apiKey;

  fetch(apiUrl)
    .then((Movies) => Movies.json())
    .then((data) => {
      movies = data.results;
      data.results.forEach((Movie) => {
        const { id, poster_path, title } = Movie;

        let container = document.getElementById("container");
        let newMovie = document.createElement("div");
        newMovie.classList.add("Movie");

        newMovie.innerHTML = `
        <a href="./movieDetails.html?id=${id}">
          <img src="${imgUrl + poster_path}">
          <span>${title}</span>
        </a>`;

        container.appendChild(newMovie);
      });
    });
}

function active(button) {
  var input = document.getElementById("searchInput");
  input.classList.toggle("hidden");

  if (input.classList.contains("hidden")) {
    button.style.backgroundImage = "url('../Images/search.png')";
    input.setAttribute("placeholder", "");
    input.value = "";
    input.setAttribute("disabled", "true");
  } else {
    button.style.backgroundImage = "url('../Images/close.png')";
    input.setAttribute("placeholder", "Search for movie ...");
    input.removeAttribute("disabled");
    input.focus();
  }
}
