public int interpret(int value, String[] commands, int[] args) {
  int commands_sz = commands.length;
  String op = "+-*";
  for(int i = 0; i<commands_sz;i++){
    if(commands[i].length() > 1){
      return -1;
    }
    boolean bad = true;
    for(int j = 0 ;j<3;j++){
      if(commands[i].charAt(0)==op.charAt(j)){
        bad = false;
        break;
      }
    }
    if(bad == true){
      return -1;
    }
  }
  int ret = value ;
  if(commands_sz != args.length){
    return -1;
  }
  for(int i=0; i<commands_sz ; i++){
    if(commands[i].charAt(0)=='+'){ret+=args[i];}
    if(commands[i].charAt(0)=='-'){ret-=args[i];}
    if(commands[i].charAt(0)=='*'){ret*=args[i];}
  }
  return ret;
}
