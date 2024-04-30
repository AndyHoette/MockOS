# Studio 21

2. It is important to make sure that the destructor is virtual so that if the destructors is call on a pointer to
a subclass then the contents of the subclass object are properly destroyed

3. The CommandPrompt doesn't have a dependencies on any concrete classes so it makes the code more flexible. We can
easily reuse this code for all kinds of fileSystems and fileFactories.