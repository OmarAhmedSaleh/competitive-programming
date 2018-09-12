def interpret(value, commands, args):
    sz = len(commands)
    ret = value
    i = 0
    while i<sz:
     if len(commands[i])>1:
         return -1
     if commands[i]!='+' and commands[i]!='*' and commands[i]!='-':
         return -1
     if commands[i]=='+':
         ret+=args[i]
     if commands[i]=='*':
        ret*=args[i]
     if commands[i]=='-':
        ret-=args[i]
     i+=1
    return ret    
