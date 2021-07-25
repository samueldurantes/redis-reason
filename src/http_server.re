open Opium

let (let.await) = Lwt.bind;

let host = "127.0.0.1";
let port = 6379;

let connection = Redis_lwt.Client.connect({ host, port });

let get_key = (req) => {
  let key = Router.param(req, "key");

  let.await conn = connection;
  let.await response = Redis_lwt.Client.get(conn, key);

  switch (response) {
    | Some(value) => Response.of_plain_text(key ++ ": " ++ value) |> Lwt.return
    | None => Response.of_plain_text("Error") |> Lwt.return
  }
};

let insert_key = (req) => {
  let key = Router.param(req, "key");
  let value = Router.param(req, "value");

  let.await conn = connection;
  let.await response = Redis_lwt.Client.set(conn, key, value);

  switch (response) {
    | true => Response.of_plain_text(key ++ ": " ++ value) |> Lwt.return
    | false => Response.of_plain_text("Error") |> Lwt.return
  }
};

App.empty
|> App.port(3301)
|> App.get("/get_key/:key", get_key)
|> App.post("/insert_key/:key/:value", insert_key)
|> App.run_command
