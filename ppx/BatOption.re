let get =
  fun
  | None => failwith("Expected Some. got None")
  | Some(v) => v;

let some = v => Some(v);
