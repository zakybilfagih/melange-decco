open Ppxlib;


class mapper = {
  as self;
  inherit class Ast_traverse.map;
  pub! signature = signature => {
    signature
    |> List.map(Signature.mapSignatureItem(self))
    |> List.concat;
  };
  pub! structure = structure => {
    structure
    |> List.map(Structure.mapStructureItem(self))
    |> List.concat;
  };
};

let structure_mapper = (_, s) => (new mapper)#structure(s);
let signature_mapper = (_, s) => (new mapper)#signature(s);

Ppxlib.Driver.V2.register_transformation(
  ~impl=structure_mapper,
  ~intf=signature_mapper,
  "decco",
);
