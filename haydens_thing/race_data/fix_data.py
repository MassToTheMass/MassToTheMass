
iterator = 0



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
    


"""
with open("haydens_thing/race_data/formatted_notwritten.txt", "r") as current_log:
    write_text = ""

    current_data = current_data.readlines()
    for line in current_data:
        if iterator == 2:
            name = line
        elif iterator == 4:
            team = line
        elif iterator == 5:
            time = line

        if iterator == 6:

            write_text += name + " " + time + " " + team

            iterator = -1
    
        iterator += 1

        """