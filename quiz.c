#include <stdio.h>
#include <string.h>

struct Quiz {
    char question[200];
    char options[4][100];
    char correct;
};

void startQuiz(struct Quiz q[], int n) {
    char answer;
    int score = 0;

    for (int i = 0; i < n; i++) {
        printf("\nQ%d: %s\n", i + 1, q[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, q[i].options[j]);
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if (answer == q[i].correct || answer == q[i].correct + 32) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer is %c\n", q[i].correct);
        }
    }

    printf("\nFinal Score: %d / %d\n", score, n);

    if (score == n)
        printf("Excellent performance!\n");
    else if (score >= n / 2)
        printf("Good job!\n");
    else
        printf("Keep practicing!\n");
}

int main() {
    struct Quiz q[3] = {
        {
            "Which language is used for system programming?",
            {"Python", "Java", "C", "HTML"},
            'C'
        },
        {
            "Which symbol is used for pointer in C?",
            {"&", "*", "#", "$"},
            'B'
        },
        {
            "Which loop executes at least once?",
            {"for", "while", "do-while", "if"},
            'C'
        }
    };

    printf("===== QUIZ GAME APPLICATION =====\n");
    startQuiz(q, 3);

    return 0;
}
