#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void cscan(vector<int>& requests, int head, int disk_size) {

    vector<int> right, left;
    int seek_count = 0;
    vector<int> seek_sequence;

    right.push_back(disk_size - 1); 
    left.push_back(0);             

  
    for (int request : requests) {
        if (request >= head) {
            right.push_back(request);
        } else {
            left.push_back(request);
        }
    }

    sort(right.begin(), right.end());
    sort(left.begin(), left.end());

    for (int track : right) {
        seek_sequence.push_back(track);
        seek_count += abs(head - track);
        head = track;
    }

    if (!left.empty()) {
        seek_count += abs(head - 0);
        head = 0;

        for (int track : left) {
            seek_sequence.push_back(track);
            seek_count += abs(head - track);
            head = track;
        }
    }

    cout << "Total number of seek operations: " << seek_count << endl;
    cout << "Seek Sequence: ";
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i];
        if (i < seek_sequence.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 50;
    int disk_size = 200; 

    cout << "Initial position of head: " << head << endl;
    cout << "Request queue: ";
    for (int req : requests) cout << req << " ";
    cout << endl;

    cscan(requests, head, disk_size);

    return 0;
}
