#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 21
#define PHONE_LEN 12

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

int main() {
    int n;
    Contact contacts[MAX_CONTACTS];
    char targetName[NAME_LEN], targetPhone[PHONE_LEN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", contacts[i].name, contacts[i].phone);
    }
    scanf("%s %s", targetName, targetPhone);

    int low = 0, high = n - 1, mid;
    int positionList[MAX_CONTACTS], positionCount = 0;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        positionList[positionCount++] = mid;

        int cmp = strcmp(targetName, contacts[mid].name);
        if (cmp == 0) {
            if (strcmp(targetPhone, contacts[mid].phone) == 0) {
                found = 1;
            }
            else {
                found = 2;
            }
            break;
        }
        else if (cmp < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("I %d\n", low);
        for (int i = n; i > low; i--) {
            contacts[i] = contacts[i - 1];
        }
        strcpy(contacts[low].name, targetName);
        strcpy(contacts[low].phone, targetPhone);
        n++;
    }

    for (int i = 0; i < positionCount; i++) {
        printf("%d ", positionList[i]);
    }
    printf("\n");

    if (found == 1) {
        printf("F %d\n", mid);
    }
    else if (found == 2) {
        printf("U %d\n", mid);
        strcpy(contacts[mid].phone, targetPhone);
    }
    else {
        printf("I %d\n", low);
    }

    return 0;
}
