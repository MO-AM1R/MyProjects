const apiKey = "api_key=9813ce01a72ca1bd2ae25f091898b1c7";
const url = "https://api.themoviedb.org/3";
const path = "/discover/movie?sort_by=popularity.desc&";
const apiUrl = url + path + apiKey;
const imgUrl = "https://image.tmdb.org/t/p/w500";

function showMovieDetails(Movie) {
  const {
    poster_path,
    title,
    adult,
    original_language,
    overview,
    release_date,
    vote_average,
    vote_count,
  } = Movie;

  let url = `url(${imgUrl + poster_path})`;

  // body Image
  {
    document.body.style.backgroundImage = url;
  }

  // Container
  {
    document.getElementById("Poster").style.backgroundImage = url;
  }

  let adultStr;
  // create information
  if (adult == true) {
    adultStr = "+18";
  } else {
    adultStr = "+12";
  }

  {
    let movieInfo = document.createElement("div");
    movieInfo.classList.add("aboutMovie");

    movieInfo.innerHTML = `
        <div>
        <span>Title: ${title}</span>
        </div>

        <div>
            <span>Overview: ${overview}</span>
        </div>

        <div>
            <span>Language: ${original_language}</span>
        </div>

        <div>
            <span>Release Date: ${release_date}</span>
        </div>

        <div>
            <span>Required Age: ${adultStr}</span>
        </div>

        <div>
            <span>Vote Count: ${vote_count}</span>
        </div>

        <div>
            <span>Vote Average: ${vote_average}</span>
        </div>
    `;

    document.getElementsByClassName("container")[0].appendChild(movieInfo);
  }
}

function getMovie(url) {
  let id = window.location.search.split("=")[1];
  fetch(url)
    .then((Movies) => Movies.json())
    .then((data) => {
      let Movies = data.results;

      Movies.forEach((Movie) => {
        if (Movie["id"] == id) {
          showMovieDetails(Movie);
        }
      });
    });
}

getMovie(apiUrl);
