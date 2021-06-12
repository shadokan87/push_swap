import subprocess
ENDL="\n"
startMessage="42 Push swap tester" + ENDL

# Usage
usage="[numbers range] [instruction cap] [pass]"
numbersRangeIe="Combination lenght as argument for your push_swap"
InstrucCapIe="Intstructions limit for each pass"
passIe="pass amount for each line of test"
usageIe="I.e: 100 1000 5000 will test 100 numbers 5000 times but will result in a KO if the instructions in a single pass are higher than 1000"
addCmdPrompt="Press enter to add another command or type 'done' to start"
#

# print start message
print(startMessage)
#

#functions
def newPrompt(message):
	returnValue = raw_input(message + "> ")
	return returnValue
#

#print usage
print("Usage: " + usage + ENDL)
print("numbers range: " + numbersRangeIe + ENDL)
print("instruction cap: " + InstrucCapIe + ENDL)
print("pass: " + passIe + ENDL)
print(usageIe)
commands = []
while 1:
	tmp = newPrompt(addCmdPrompt)
	if tmp == "done":
		break
	commands += [tmp]
print(commands)
