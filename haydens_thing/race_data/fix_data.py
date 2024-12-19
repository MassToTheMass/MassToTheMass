
team_names = ["Roy"]


with open("haydens_thing/race_data/unformatted_data.txt", "r") as current_data:

    write_text = ""

    current_data = current_data.readlines()
    for line in current_data:
        if line.strip() in team_names:
            write_text += line
        if len(line) <= 4:
            pass
        else:
            write_text += line

with open("haydens_thing/race_data/unformatted_data.txt", "w") as new_data_log:

    new_data_log.write(write_text)
    
iterator = 0
with open("haydens_thing/race_data/unformatted_data.txt", "r") as current_log:
    write_text = ""

    current_data = current_log.readlines()
    for line in current_data:

        print(iterator)
        print(line)

        if iterator == 0:
            name = line.strip()
        elif iterator == 1:
            team = line.strip()
        elif iterator == 2:
            time = line.strip()
        elif iterator == 3:

            parsed_string = line.split(" ")
            index_of_year = parsed_string.index("Yr:")
            grade = parsed_string[index_of_year + 1].strip()

            name = name.split(" ")[0] + "_" + name.split(" ")[1]
            time = time.split(".")[0]

            team_split = team.split(" ")
            team = ""
            for token in team_split:
                team += token
                team += "_"
            team = team[:-1]
                

            write_text += name + " " + time + " " + team + " " + grade + "\n"

            iterator = -1
        iterator += 1

with open("haydens_thing/race_data/ra0006.txt", "w") as current_log:
    current_log.write(write_text)