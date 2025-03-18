

function main()

  Name_lib = "TreinAi"

  arguments = {
    {
      arg="help",
      func=Help,
      description="Describes all building sectors."
    },
    {
      arg="dependencies",
      func=Install_dependencies,
      description="Installs the necessary external dependencies."
    },
    {
      arg="silver",
      func=Initialize_silver,
      description="Implements the necessary imports for 'include' and 'auto complete'."
    },
    {
      arg="comp",
      func=Comp,
      description="Copilat the main.c."
    }
  }

  Get_args()

  print("\tEND\n\n")
end





