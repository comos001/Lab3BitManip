# Test file for "Lab3BitManip"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n
test "PINA: 0x01 => PORTC: 96"
# Set inputs
setPINA 0x01
# # Continue for several ticks 
continue 2
# # Set expect values
expectPORTC 96
# # Check pass/fail
checkResult

test "PINA: 0x06 => PORTC: 0b0011 1000"
# Set inputs
setPINA 0x06
# # Continue for several ticks
continue 2
# # Set expect values
expectPORTC 0b00111000
# # Check pass/fail
checkResult

# # Example test:
test "PINA: 0x0A => PORTC: 0b0011 1110"
# # Set inputs
setPINA 0x0F
# # Continue for several ticks
continue 2
# # Set expect values
expectPORTC 0b00111111
# # Check pass/fail
checkResult

test "PINA: 0x3F => PORTC: 0b1011 1111"
# Set inputs
setPINA 0x3F
# # Continue for several ticks
continue 2
# # Set expect values
expectPORTC 0b10111111
# # Check pass/fail
checkResult

# # Example test:
test "PINA: 0x7F => PORTC: 0b0011 1111"
# # Set inputs
setPINA 0x7F
# # Continue for several ticks
continue 2
# # Set expect values
expectPORTC 0b00111111
# # Check pass/fail
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
