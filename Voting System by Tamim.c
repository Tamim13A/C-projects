#include <stdio.h>
#include <string.h>

#define CANDIDATE_COUNT 3
#define MAX_NAME_LENGTH 50

// Candidate structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Function prototypes
void displayCandidates(Candidate candidates[], int count);
void castVote(Candidate candidates[], int count);
void displayResults(Candidate candidates[], int count);

int main() {
    // Initialize candidates
    Candidate candidates[CANDIDATE_COUNT] = {
        {"Tamim", 0},
        {"Tonmoy", 0},
        {"Tonu", 0}
    };

    int voterCount, i;

    // Input number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &voterCount);

    // Cast votes
    for (i = 0; i < voterCount; i++) {
        printf("\nVoter %d:\n", i + 1);
        displayCandidates(candidates, CANDIDATE_COUNT);
        castVote(candidates, CANDIDATE_COUNT);
    }

    // Display voting results
    displayResults(candidates, CANDIDATE_COUNT);

    return 0;
}

// Function to display the list of candidates
void displayCandidates(Candidate candidates[], int count) {
    int i;
    printf("Candidates:\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
void castVote(Candidate candidates[], int count) {
    int choice;
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &choice);

    // Validate the choice
    if (choice < 1 || choice > count) {
        printf("Invalid choice! Please try again.\n");
        castVote(candidates, count); // Recursive call for valid input
    } else {
        candidates[choice - 1].votes++;
    }
}

// Function to display the voting results
void displayResults(Candidate candidates[], int count) {
    int i;
    printf("\nVoting Results:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Find the winner
    int maxVotes = 0;
    int winnerIndex = 0;
    for (i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("Winner: %s with %d votes\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
}











































