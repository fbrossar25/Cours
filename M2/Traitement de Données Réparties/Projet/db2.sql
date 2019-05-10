DROP TABLE IF EXISTS castings;
DROP TABLE IF EXISTS films;
DROP TABLE IF EXISTS actors;

CREATE TABLE films(
    film_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR (500),
    year INTEGER,
    genre_list VARCHAR(500)
);

CREATE TABLE actors(
    actor_id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(500)
);

CREATE TABLE castings(
    actor_id INTEGER NOT NULL,
    film_id INTEGER NOT NULL,
    FOREIGN KEY fk_actor(actor_id)
    REFERENCES actors(actor_id)
    ON UPDATE CASCADE
    ON DELETE RESTRICT,
    FOREIGN KEY fk_film(film_id)
    REFERENCES films(film_id)
    ON UPDATE CASCADE
    ON DELETE RESTRICT
);