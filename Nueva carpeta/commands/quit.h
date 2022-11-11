#ifndef QUIT_H
#define QUIT_H

bool quit_semantic(const string* tokens, const int total_tokens)
{
    if(tokens is null or total_tokens is 0 or total_tokens > 1)
        return false;
    return true;
}

void quit()
{
    //kill_Prompt(p);
    exit(EXIT_SUCCESS);
}

#endif