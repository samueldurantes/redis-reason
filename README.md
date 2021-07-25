## redis-ocaml
A Redis client in Reason

## Dependencies
- esy
- docker and docker-compose (Optional for tests)

## Quick start
```bash
# install dependencies 
$ esy install

# build the project
$ esy b dune build src/http_server.exe

# up redis container on Docker
$ docker-compose -f docker-compose.yml up

# exec the project
$ esy dune exec src/http_server.exe
```

## License
Lincesed under the [MIT](https://github.com/samueldurantes/redis-ocaml/blob/master/LICENSE)