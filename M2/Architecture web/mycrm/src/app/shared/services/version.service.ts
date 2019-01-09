import { BehaviorSubject } from 'rxjs';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class VersionService {
  private versionObservable: BehaviorSubject<number>  = new BehaviorSubject<number>(7);
  constructor() { }
  getVersion(): number {
    return this.versionObservable.getValue();
  }
  incrementVersion(): void {
    this.versionObservable.next(this.getVersion() + 1);
  }
  decrementVersion(): void {
    this.versionObservable.next(this.getVersion() - 1);
  }
  getObservable() {
    return this.versionObservable;
  }
}
