(* Frama-C journal generated at 13:59 the 19/10/2018 *)

exception Unreachable
exception Exception of string

(* Run the user commands *)
let run () =
  Project.set_keep_current false;
  File.init_from_cmdline ();
  Dynamic.Parameter.String.set ""
    "/home/florian/Documents/certification/TP1/mini.c";
  File.init_from_cmdline ();
  Dynamic.Parameter.String.set "" "";
  Dynamic.Parameter.String.set ""
    "/home/florian/Documents/certification/TP1/mini.c";
  File.init_from_cmdline ();
  Project.set_keep_current false;
  Dynamic.Parameter.String.set "" "";
  Dynamic.Parameter.String.set ""
    "/home/florian/Documents/certification/TP1/mini.c";
  File.init_from_cmdline ();
  Project.set_keep_current false;
  ()

(* Main *)
let main () =
  Journal.keep_file "./.frama-c/frama_c_journal.ml";
  try run ()
  with
  | Unreachable -> Kernel.fatal "Journal reaches an assumed dead code" 
  | Exception s -> Kernel.log "Journal re-raised the exception %S" s
  | exn ->
    Kernel.fatal
      "Journal raised an unexpected exception: %s"
      (Printexc.to_string exn)

(* Registering *)
let main : unit -> unit =
  Dynamic.register
    ~plugin:"Frama_c_journal.ml"
    "main"
    (Datatype.func Datatype.unit Datatype.unit)
    ~journalize:false
    main

(* Hooking *)
let () = Cmdline.run_after_loading_stage main; Cmdline.is_going_to_load ()
