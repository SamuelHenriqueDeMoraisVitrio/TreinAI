


local function Preparation(cc, main, flags, path_out, name_out)
  local path_out = path_out .. "/"
  darwin.dtw.remove_any(path_out .. name_out)
  darwin.dtw.write_file(path_out .. "cache", "")
  darwin.dtw.remove_any(path_out .. "cache")

  local result = os.execute(cc .. ' ' .. flags .. " -o " .. path_out .. name_out .. " src/" .. main)

  if not result then
    os.exit(1)
  end

  print("\n\tCompiled the" .. name_out .. " in " .. path_out .. "\n")
end

function Comp_testing()
  Preparation("gcc", "testing.c ", "", "test/c", "test.out")
  os.execute("test/c/test.out > test/c/teste.txt")
end

function Comp()
  local path_out_bin_to_linux = "realeses/linux" .. Name_lib
  Preparation("gcc", "main.c", "", path_out_bin_to_linux, Name_lib .. "_EN.out")
  Preparation("gcc", "main.c", "-DTREINAI_SYSTEM_MESSAGES_BR", path_out_bin_to_linux, Name_lib .. "_BR")
  Preparation("gcc", "main.c", "-DTREINAI_SYSTEM_MESSAGES_DE", path_out_bin_to_linux, Name_lib .. "_DE")
  Preparation("gcc", "main.c", "-DTREINAI_SYSTEM_MESSAGES_ES", path_out_bin_to_linux, Name_lib .. "_ES")
  Preparation("gcc", "main.c", "-DTREINAI_SYSTEM_MESSAGES_FR", path_out_bin_to_linux, Name_lib .. "_FR")

  darwin.dtw.remove_any(path_out_bin_to_linux .. ".zip")
  os.execute("zip -r " .. path_out_bin_to_linux .. ".zip " .. path_out_bin_to_linux)
end



