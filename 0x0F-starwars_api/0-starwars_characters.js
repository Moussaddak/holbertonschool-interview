#!/usr/bin/node

const request = require('request');
const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}/`;

request(url, async function (error, response, body) {
  if (error) { console.log(error); }

  const movie = JSON.parse(body);
  const chars = movie.characters;

  for (let i = 0; i < chars.length; i++) {
    const name = await new Promise(function (resolve, reject) {
      request(chars[i], 'utf-8', function (error, response, body) {
        if (error) { reject(error); }
        resolve(JSON.parse(body).name);
      });
    });
    console.log(name);
  }
});
