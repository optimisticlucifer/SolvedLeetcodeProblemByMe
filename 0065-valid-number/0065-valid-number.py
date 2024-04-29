class Solution:
    def isNumber(self, s: str) -> bool:

        s = s.replace("E", "e")
        stack = s.split("e")
        if len(stack) > 2:
            return False

        def is_int(s):
            if not s:   # check if empty
                return False
            if s[0] not in "0123456789+-":  # check first char
                return False
            for i in range(len(s) - 1, 0, -1):  # check all other chars
                if s[i] not in "0123456789":
                    return False
            for char in s:  # at least has one digit in s
                if char in "01234567890":
                    return True
            return False

        def is_dec(s):
            if not s:   # check if empty
                return False
            if len(s.split(".")) != 2:  # check if there is one "."
                return False
            if s[0] not in "0123456789.+-": # check first char
                return False
            for i in range(len(s) - 1, 0, -1): # check all other chars
                if s[i] not in "0123456789.":
                    return False
            for char in s:      # at least has one digit in s
                if char in "0123456789":
                    return True
            return False            

        if not is_dec(stack[0]) and not is_int(stack[0]):
            return False
        if len(stack) > 1 and not is_int(stack[1]):
            return False
        return True