open NodeExtHttp;

let server =
  createServer((_, res) => {
    open NodeExtStream.WritableStream;
    writeString(res, ~data="Hello world", ()) |> ignore;
    endStream(res);
    ();
  });

Server.listenWithPort(server, 60023);

server
|> NodeExtNet.Server.on(
     `listening(() => Js.log("listening on port 60023")),
   )
|> ignore;