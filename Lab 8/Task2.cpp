#include <iostream>
#include <string>

using namespace std;

struct SongNode {
    int playCount;
    string title;
    SongNode* left;
    SongNode* right;

    SongNode(int count, string t) {
        playCount = count;
        title = t;
        left = NULL;
        right = NULL;
    }
};

SongNode* insertSong(SongNode* node, int count, string title) {
    if (node == NULL) {
        return new SongNode(count, title);
    }

    if (count < node->playCount) {
        node->left = insertSong(node->left, count, title);
    } else if (count > node->playCount) {
        node->right = insertSong(node->right, count, title);
    }
    
    return node;
}

SongNode* searchSong(SongNode* node, int count) {
    if (node == NULL || node->playCount == count) {
        return node;
    }

    if (count < node->playCount) {
        return searchSong(node->left, count);
    }

    return searchSong(node->right, count);
}

void inorderDisplay(SongNode* node) {
    if (node == NULL) {
        return;
    }
    inorderDisplay(node->left);
    cout << "[" << node->playCount << " plays] " << node->title << endl;
    inorderDisplay(node->right);
}

void postorderDisplay(SongNode* node) {
    if (node == NULL) {
        return;
    }
    postorderDisplay(node->left);
    postorderDisplay(node->right);
    cout << "[" << node->playCount << " plays] " << node->title << endl;
}

SongNode* findMin(SongNode* node) {
    SongNode* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

SongNode* deleteSong(SongNode* node, int count) {
    if (node == NULL) {
        return node;
    }

    if (count < node->playCount) {
        node->left = deleteSong(node->left, count);
    } else if (count > node->playCount) {
        node->right = deleteSong(node->right, count);
    } else {
        if (node->left == NULL) {
            SongNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            SongNode* temp = node->left;
            delete node;
            return temp;
        }

        SongNode* temp = findMin(node->right);
        node->playCount = temp->playCount;
        node->title = temp->title;
        node->right = deleteSong(node->right, temp->playCount);
    }
    return node;
}


int main() {
    cout << "--- Task 2: Music App BST ---" << endl;
    
    SongNode* musicRoot = NULL;
    musicRoot = insertSong(musicRoot, 150, "Song C");
    musicRoot = insertSong(musicRoot, 100, "Song A");
    musicRoot = insertSong(musicRoot, 200, "Song E");
    musicRoot = insertSong(musicRoot, 120, "Song B");
    musicRoot = insertSong(musicRoot, 180, "Song D");
    musicRoot = insertSong(musicRoot, 250, "Song F");

    cout << "\nInorder (Least to Most Played):" << endl;
    inorderDisplay(musicRoot);

    cout << "\nPostorder (Removal Order):" << endl;
    postorderDisplay(musicRoot);

    cout << "\nSearching for song with 120 plays:" << endl;
    SongNode* foundSong = searchSong(musicRoot, 120);
    if (foundSong != NULL) {
        cout << "Found: " << foundSong->title << endl;
    } else {
        cout << "Not found." << endl;
    }
    
    cout << "\nSearching for song with 500 plays:" << endl;
    SongNode* notFoundSong = searchSong(musicRoot, 500);
    if (notFoundSong != NULL) {
        cout << "Found: " << notFoundSong->title << endl;
    } else {
        cout << "Not found." << endl;
    }

    cout << "\nDeleting song with 150 plays (Song C)..." << endl;
    musicRoot = deleteSong(musicRoot, 150);

    cout << "\nUpdated Inorder Display:" << endl;
    inorderDisplay(musicRoot);

    return 0;
}
