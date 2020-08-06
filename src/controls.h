#define CONTROLS_LEFT 'h'
#define CONTROLS_DOWN 'j'
#define CONTROLS_UP 'k'
#define CONTROLS_RIGHT 'l'

void start_controls() {
  // TODO: start a thread that reads controls
}

char readkey() {
  FILE *fp = popen("read -n 1 -r -s key; echo $key", "r");
  if (fp == NULL) {
    exit(1);
  }
  char c = fgetc(fp);
  pclose(fp);

  return c;
}
