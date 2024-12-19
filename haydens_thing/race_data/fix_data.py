

with open("haydens_thing/race_data/unformatted_data", "r") as current_data:

    write_text = ""

    current_data = current_data.readlines()
    for line in current_data:
        if len(line) <= 3:
            pass
        else:
            write_text += line

with open("haydens_thing/race_data/formatted_notwritten.txt", "w") as new_data_log:

    new_data_log.write(write_text)
    
iterator = 0
with open("haydens_thing/race_data/formatted_notwritten.txt", "r") as current_log:
    write_text = ""

    current_data = current_log.readlines()
    for line in current_data:
        if iterator == 0:
            name = line
        elif iterator == 1:
            team = line
        elif iterator == 2:
            time = line
        elif iterator == 3:

            parsed_string = line.split(" ")
            print(parsed_string)
            index_of_year = parsed_string.index("Yr:")
            grade = parsed_string[index_of_year + 1]

            iterator = 0
        iterator += 1