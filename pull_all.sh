#!/bin/bash

# Ensure the script stops if any command fails
set -e

# Pull the latest changes for the parent repository
echo "Pulling changes for the parent repository..."
git pull

# Update and pull changes for submodules
echo "Updating and pulling changes for submodules..."
git submodule foreach --recursive '
  echo "Entering submodule: $name"
  
  # Check if the submodule is initialized
  if [ "$(git rev-parse --is-inside-work-tree 2>/dev/null)" != "true" ]; then
    echo "Submodule $name is not initialized. Initializing..."
    git submodule update --init
  fi
  
  # Check if the submodule is in a detached HEAD state
  branch=$(git symbolic-ref --short HEAD || echo "detached")
  if [ "$branch" = "detached" ]; then
    echo "Submodule $name is in a detached HEAD state. Attempting to fix..."
    git checkout main || echo "Branch 'main' does not exist in $name. Please check manually."
  fi
  
  # Pull the latest changes from the remote branch
  if [ "$branch" != "detached" ]; then
    echo "Pulling changes for branch $branch in $name..."
    git pull origin $branch
  fi
'

# Update submodule references in the parent repository
echo "Updating submodule references in the parent repository..."
git submodule update --init --recursive

echo "All submodules and the parent repository are up to date!"
