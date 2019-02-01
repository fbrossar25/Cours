import { TestBed } from '@angular/core/testing';

import { ComapiService } from './comapi.service';

describe('ComapiService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: ComapiService = TestBed.get(ComapiService);
    expect(service).toBeTruthy();
  });
});
