

with open("jv_state.txt", "r") as current_data:
    current_data = current_data.readlines()

    write_text = ""

    for line in current_data:
        line = line.strip()
        if len(line) < 5:
            pass
        elif line == "\n":
            pass
        else:
            print(line)
            write_text += (line + "\n")

with open("new_jv_state.txt", "w") as new_data_log:

    new_data_log.write(write_text)
    